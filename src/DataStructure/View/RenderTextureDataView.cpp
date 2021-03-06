#include "RenderTextureDataView.hh"
#include "ui_RenderTextureDataView.h"

#include <QErrorMessage>
#include <assert.h>

RenderTextureDataView::RenderTextureDataView(AbstractData *data, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RenderTextureDataView)
{
    ui->setupUi(this);

    _pixelFormats.append("GL_DEPTH_COMPONENT16");
    _pixelFormats.append("GL_DEPTH_COMPONENT24");
    _pixelFormats.append("GL_DEPTH_COMPONENT32");
    _pixelFormats.append("GL_DEPTH24_STENCIL8");
    _pixelFormats.append("GL_R8");
    _pixelFormats.append("GL_R16UI");
    _pixelFormats.append("GL_R16F");
    _pixelFormats.append("GL_R32F");
    _pixelFormats.append("GL_RG8");
    _pixelFormats.append("GL_RG16UI");
    _pixelFormats.append("GL_RG16F");
    _pixelFormats.append("GL_RG32F");
    _pixelFormats.append("GL_RGB8");
    _pixelFormats.append("GL_RGB16UI");
    _pixelFormats.append("GL_RGB16F");
    _pixelFormats.append("GL_RGB32F");
    _pixelFormats.append("GL_RGBA8");
    _pixelFormats.append("GL_RGBA16UI");
    _pixelFormats.append("GL_RGBA16F");
    _pixelFormats.append("GL_RGBA32F");

    _filterModes.append("LINEAR");
    _filterModes.append("NEAREST");

    _wrapModes.append("REPEAT");
    _wrapModes.append("MIRRORED REPEAT");
    _wrapModes.append("CLAMP");

    ui->texturePixelFormat->addItems(_pixelFormats);
    ui->magFilter->addItems(_filterModes);
    ui->minFilter->addItems(_filterModes);
    ui->horizontalWrap->addItems(_wrapModes);
    ui->verticalWrap->addItems(_wrapModes);

    QObject::connect(ui->saveChanges, SIGNAL(released()),
                     data, SLOT(saveChanges()));
}

RenderTextureDataView::~RenderTextureDataView()
{
    delete ui;
}
